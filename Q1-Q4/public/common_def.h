
#ifndef __COMMON_DEF_H__
#define __COMMON_DEF_H__ 1

#define VERBOSE_

typedef enum {
	kErrorCode_Ok = 0,
	kErrorCode_NullPointer = -1,
	kErrorCode_ObjectNotFound = -2,
	kErrorCode_InvalidParameter = -3,
} ErrorCode;

static const char* kErrorCodeText[] = {
  "OK",
  "NULL Pointer"
  "Object not found",
  "Invalid parameter",
};

#endif // __COMMON_DEF_H__
