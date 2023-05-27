#include "datamodel.h"

DataModel::~DataModel() {
    if (db_.isOpen()) {
        db_.close();
    }
}
