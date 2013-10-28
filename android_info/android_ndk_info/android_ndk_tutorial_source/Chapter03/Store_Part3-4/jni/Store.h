#ifndef _STORE_H_
#define _STORE_H_

#include "jni.h"
#include <stdint.h>


/*
 * Constants.
 */
#define STORE_MAX_CAPACITY 16


/*
 * Types handled by the store.
 */
typedef enum {
    StoreType_Integer, StoreType_String, StoreType_Color,
    StoreType_IntegerArray, StoreType_ColorArray
} StoreType;


/**
 * Store data structures.
 */
typedef union {
    int32_t  mInteger;
    char*    mString;
    jobject  mColor;
    int32_t* mIntegerArray;
    jobject* mColorArray;
} StoreValue;

typedef struct {
    char* mKey;
    StoreType mType;
    StoreValue mValue;
    int32_t mLength; // Used only for arrays.
} StoreEntry;

typedef struct {
    StoreEntry mEntries[STORE_MAX_CAPACITY];
    int32_t mLength;
} Store;


/*
 * Store helper methods.
 */
uint32_t isEntryValid(JNIEnv* pEnv, StoreEntry* pEntry,
                      StoreType pType);

StoreEntry* allocateEntry(JNIEnv* pEnv, Store* pStore, jstring pKey);

StoreEntry* findEntry(JNIEnv* pEnv, Store* pStore, jstring pKey,
                      int32_t* pError);

void releaseEntryValue(JNIEnv* pEnv, StoreEntry* pEntry);


/*
 * Methods to raise Java exceptions.
 */
void throwInvalidTypeException(JNIEnv* pEnv);

void throwNotExistingKeyException(JNIEnv* pEnv);

void throwStoreFullException(JNIEnv* pEnv);

#endif
