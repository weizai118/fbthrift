/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include "thrift/compiler/test/fixtures/includes/gen-cpp2/module_types.h"
#include <thrift/lib/cpp/TApplicationException.h>
#include <folly/io/IOBuf.h>
#include <folly/io/IOBufQueue.h>
#include <thrift/lib/cpp/transport/THeader.h>
#include <thrift/lib/cpp2/server/Cpp2ConnContext.h>
#include <thrift/lib/cpp2/GeneratedCodeHelper.h>
#include <thrift/lib/cpp2/GeneratedSerializationCodeHelper.h>

#include <thrift/lib/cpp2/protocol/BinaryProtocol.h>
#include <thrift/lib/cpp2/protocol/CompactProtocol.h>
namespace cpp2 {

template <typename T_MyStruct_MyIncludedField_struct_setter>
 ::cpp2::Included& MyStruct::set_MyIncludedField(T_MyStruct_MyIncludedField_struct_setter&& MyIncludedField_) {
  MyIncludedField = std::forward<T_MyStruct_MyIncludedField_struct_setter>(MyIncludedField_);
  __isset.MyIncludedField = true;
  return MyIncludedField;
}

template <class Protocol_>
uint32_t MyStruct::read(Protocol_* iprot) {
  uint32_t xfer = 0;
  std::string fname;
  apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using apache::thrift::TProtocolException;


  while (true) {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == apache::thrift::protocol::T_STOP) {
      break;
    }
    if (fid == std::numeric_limits<int16_t>::min()) {
      if (fname == "MyIncludedField") {
        fid = 1;
        ftype = apache::thrift::protocol::T_STRUCT;
      }
      else if (fname == "MyIncludedInt") {
        fid = 2;
        ftype = apache::thrift::protocol::T_I64;
      }
    }
    switch (fid) {
      case 1:
      {
        if (ftype == apache::thrift::protocol::T_STRUCT) {
          xfer += ::apache::thrift::Cpp2Ops<  ::cpp2::Included>::read(iprot, &this->MyIncludedField);
          this->__isset.MyIncludedField = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      }
      case 2:
      {
        if (ftype == apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->MyIncludedInt);
          this->__isset.MyIncludedInt = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      }
      default:
      {
        xfer += iprot->skip(ftype);
        break;
      }
    }
    xfer += iprot->readFieldEnd();
  }
  xfer += iprot->readStructEnd();

  return xfer;
}

template <class Protocol_>
uint32_t MyStruct::serializedSize(Protocol_ const* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->serializedStructSize("MyStruct");
  xfer += prot_->serializedFieldSize("MyIncludedField", apache::thrift::protocol::T_STRUCT, 1);
  xfer += ::apache::thrift::Cpp2Ops<  ::cpp2::Included>::serializedSize(prot_, &this->MyIncludedField);
  xfer += prot_->serializedFieldSize("MyIncludedInt", apache::thrift::protocol::T_I64, 2);
  xfer += prot_->serializedSizeI64(this->MyIncludedInt);
  xfer += prot_->serializedSizeStop();
  return xfer;
}

template <class Protocol_>
uint32_t MyStruct::serializedSizeZC(Protocol_ const* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->serializedStructSize("MyStruct");
  xfer += prot_->serializedFieldSize("MyIncludedField", apache::thrift::protocol::T_STRUCT, 1);
  xfer += ::apache::thrift::Cpp2Ops<  ::cpp2::Included>::serializedSizeZC(prot_, &this->MyIncludedField);
  xfer += prot_->serializedFieldSize("MyIncludedInt", apache::thrift::protocol::T_I64, 2);
  xfer += prot_->serializedSizeI64(this->MyIncludedInt);
  xfer += prot_->serializedSizeStop();
  return xfer;
}

template <class Protocol_>
uint32_t MyStruct::write(Protocol_* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->writeStructBegin("MyStruct");
  xfer += prot_->writeFieldBegin("MyIncludedField", apache::thrift::protocol::T_STRUCT, 1);
  xfer += ::apache::thrift::Cpp2Ops<  ::cpp2::Included>::write(prot_, &this->MyIncludedField);
  xfer += prot_->writeFieldEnd();
  xfer += prot_->writeFieldBegin("MyIncludedInt", apache::thrift::protocol::T_I64, 2);
  xfer += prot_->writeI64(this->MyIncludedInt);
  xfer += prot_->writeFieldEnd();
  xfer += prot_->writeFieldStop();
  xfer += prot_->writeStructEnd();
  return xfer;
}

} // cpp2
namespace apache { namespace thrift {

}} // apache::thrift
namespace cpp2 {

} // cpp2
