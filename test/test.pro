QT += core network
QT -= gui

CONFIG += c++11

TARGET = test
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    ../src/chain/action.cpp \
    ../src/chain/chainmanager.cpp \
    ../src/chain/eosbytewriter.cpp \
    ../src/chain/eosnewaccount.cpp \
    ../src/chain/packedtransaction.cpp \
    ../src/chain/signedtransaction.cpp \
    ../src/chain/transaction.cpp \
    ../src/chain/transactionheader.cpp \
    ../src/chain/typeaccountpermissionweight.cpp \
    ../src/chain/typeauthority.cpp \
    ../src/chain/typekeypermissionweight.cpp \
    ../src/chain/typename.cpp \
    ../src/chain/typepermissionlevel.cpp \
    ../src/Crypto/aes.c \
    ../src/Crypto/base58.c \
    ../src/Crypto/rmd160.c \
    ../src/Crypto/sha2.c \
    ../src/Crypto/sha3.c \
    ../src/Crypto/uECC.c \
    ../src/ec/eos_key_encode.cpp \
    ../src/ec/sha512.cpp \
    ../src/ec/typechainid.cpp \
    ../src/utility/utils.cpp \
    ../src/utility/httpclient.cpp

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    ../src/chain/action.h \
    ../src/chain/chainbase.h \
    ../src/chain/chainmanager.h \
    ../src/chain/eosbytewriter.h \
    ../src/chain/eosnewaccount.h \
    ../src/chain/packedtransaction.h \
    ../src/chain/signedtransaction.h \
    ../src/chain/transaction.h \
    ../src/chain/transactionheader.h \
    ../src/chain/typeaccountpermissionweight.h \
    ../src/chain/typeauthority.h \
    ../src/chain/typekeypermissionweight.h \
    ../src/chain/typename.h \
    ../src/chain/typepermissionlevel.h \
    ../src/Crypto/aes.h \
    ../src/Crypto/aes.hpp \
    ../src/Crypto/libbase58.h \
    ../src/Crypto/macros.h \
    ../src/Crypto/options.h \
    ../src/Crypto/rmd160.h \
    ../src/Crypto/sha2.h \
    ../src/Crypto/sha3.h \
    ../src/Crypto/uECC.h \
    ../src/ec/eos_key_encode.h \
    ../src/ec/sha512.h \
    ../src/ec/typechainid.h \
    ../src/utility/utils.h \
    ../src/utility/httpclient.h
