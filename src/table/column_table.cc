#include "column_table.h"
#include <cstring>
#include <iostream>

// 字节数，32位整数/8
const int B = 4;
namespace bytedance_db_project {
ColumnTable::ColumnTable() {}

ColumnTable::~ColumnTable() {
  if (columns_ != nullptr) {
    delete columns_;
    columns_ = nullptr;
  }
}

//
// columnTable, which stores data in column-major format.
// That is, data is laid out like
//   col 1 | col 2 | ... | col m.
//
void ColumnTable::Load(BaseDataLoader *loader) {
  num_cols_ = loader->GetNumCols();
  std::vector<char *> rows = loader->GetRows();
  num_rows_ = rows.size();
  columns_ = new char[FIXED_FIELD_LEN * num_rows_ * num_cols_];

  for (int32_t row_id = 0; row_id < num_rows_; row_id++) {
    auto cur_row = rows.at(row_id);
    for (int32_t col_id = 0; col_id < num_cols_; col_id++) {
      int32_t offset = FIXED_FIELD_LEN * ((col_id * num_rows_) + row_id);
      std::memcpy(columns_ + offset, cur_row + FIXED_FIELD_LEN * col_id,
                  FIXED_FIELD_LEN);
    }
  }
}

int32_t ColumnTable::GetIntField(int32_t row_id, int32_t col_id) {
    // Get offset of this field
    int64_t offset = FIXED_FIELD_LEN * (col_id * num_rows_ + row_id);
    int32_t field;
    memcpy(&field, columns_ + offset, FIXED_FIELD_LEN);
    return field;
}

void ColumnTable::PutIntField(int32_t row_id, int32_t col_id, int32_t field) {
    // Get offset of this field
    int64_t offset = FIXED_FIELD_LEN * (col_id * num_rows_ + row_id);
    memcpy(columns_ + offset, &field, FIXED_FIELD_LEN);
}

int64_t ColumnTable::ColumnSum() {
    int64_t sum = 0;
    for (int i = 0; i < num_rows_; i++) {
        sum += GetIntField(i, 0);
    }
    return sum;
}

int64_t ColumnTable::PredicatedColumnSum(int32_t threshold1,
                                         int32_t threshold2) {
  // TODO: Implement this!
  return 0;
}

int64_t ColumnTable::PredicatedAllColumnsSum(int32_t threshold) {
  // TODO: Implement this!
  return 0;
}

int64_t ColumnTable::PredicatedUpdate(int32_t threshold) {
  // TODO: Implement this!
  return 0;
}
} // namespace bytedance_db_project