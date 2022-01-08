#include "row_table.h"
#include <cstring>

// 字节数，32位整数/8
const int B = 4;
namespace bytedance_db_project {
RowTable::RowTable() {}

RowTable::~RowTable() {
  if (rows_ != nullptr) {
    delete rows_;
    rows_ = nullptr;
  }
}

void RowTable::Load(BaseDataLoader *loader) {
  num_cols_ = loader->GetNumCols();
  auto rows = loader->GetRows();
  num_rows_ = rows.size();
  rows_ = new char[FIXED_FIELD_LEN * num_rows_ * num_cols_];
  for (auto row_id = 0; row_id < num_rows_; row_id++) {
    auto cur_row = rows.at(row_id);
    std::memcpy(rows_ + row_id * (FIXED_FIELD_LEN * num_cols_), cur_row,
                FIXED_FIELD_LEN * num_cols_);
  }
}

int32_t RowTable::GetIntField(int32_t row_id, int32_t col_id) {
  // Get offset of this field
  int64_t offset = FIXED_FIELD_LEN * ((row_id * num_cols_) + col_id);
  int32_t field;
  memcpy(&field, rows_ + offset, FIXED_FIELD_LEN);
  return field;
}

void RowTable::PutIntField(int32_t row_id, int32_t col_id, int32_t field) {
    // Get offset of this field
    int64_t offset = FIXED_FIELD_LEN * ((row_id * num_cols_) + col_id);
    memcpy(rows_ + offset, &field, FIXED_FIELD_LEN);
}

int64_t RowTable::ColumnSum() {
    int64_t sum = 0;
    for (int i = 0; i < num_rows_; i++) {
        sum += GetIntField(i, 0);
    }
    return sum;
}

int64_t RowTable::PredicatedColumnSum(int32_t threshold1, int32_t threshold2) {
    int64_t sum = 0;
    for (int i = 0; i < num_rows_; i++) {
        int32_t col1 = GetIntField(i, 1);
        int32_t col2 = GetIntField(i, 2);
        if (col1 > threshold1 && col2 < threshold2) {
            sum += GetIntField(i, 0);
        }
    }
    return sum;
}

int64_t RowTable::PredicatedAllColumnsSum(int32_t threshold) {
    int64_t sum = 0;
    for (int i = 0; i < num_rows_; i++) {
        int32_t col0 = GetIntField(i, 0);
        if (col0 > threshold) {
            for (int j = 0; j < num_cols_; j++) {
                sum += GetIntField(i, j);
            }
        }
    }
    return sum;
}

int64_t RowTable::PredicatedUpdate(int32_t threshold) {
    int64_t sum = 0;
    for (int i = 0; i < num_rows_; i++) {
        int32_t col0 = GetIntField(i, 0);
        if (col0 < threshold) {
            int32_t col2 = GetIntField(i, 2);
            int32_t col3 = GetIntField(i,  3);
            PutIntField(i, 3, col2 + col3);
            sum++;
        }
    }
    return sum;
}
} // namespace bytedance_db_project