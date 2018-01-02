################################################################################
## @file: 	template.bin.mk
## @author:	徐陈锋 <johnx@mail.ustc.edu.cn>
## @brief	生成可执行文件的makefile模板.
## @version	1.0
###############################################################################

## NOTE: 这里认为一个生成目标对应一个工程. '当前目录'指$(MAKEFILE)所在目录.

## makefile 文件名，默认为 'Makefile'. 如果文件名不为'Makefile', 必须设定.
MAKEFILE	:=

## 生成目标名称. 生成的目标文件名为$(TARGET).$(VERSION), 非release还要加上当
## 前'年月日'. 必须设定.
TARGET		:= test

## 生成目标的输出目录, 默认为当前目录.
#OUTDIR		:=

## 版本号，默认为当前'年月日'，'make release'时为'r年月日'.
#VERSION	:=

## 是否需要版本号，默认是需要。值0/1: 0, 需要; 1, 不需要.
NVERSION	:= 1

## 额外包含目录, 形式为'-I_THE_DIR_', 每个'-I'一个目录, 用多个'-I'来指定多个
## 包含目录.
INCLUDES	:= -I. -I.. 

## 指定所依赖的库. 如果依赖的库的名称为'libLIBNAME.so', 则用'-lLIBNAME'指定
## 或用'_THE_DIR_WHERE_LIB_LIES_/libLIBNAME.so'. 在第一中方式下, 如果库所在
## 的目录不再系统默认的目录, 也没有在/etc/ld.so.conf中出现, 用'-L'指定, 如,
## '-L_THE_DIR_WHERE_LIB_LIES_'. 每一个'-l'和'-L'指定一项, 用多个'-l'/'-L'指
## 定多项.
LIBS		:= -lACE 

## 生成目标所在工程的头文件的后缀名, 默认为'.h'. 如果设定了'FILES_H', 无需再
## 设定'FILE_H_SUFFIX', 也不起作用.
#FILE_H_SUFFIX	:= .h

## 生成目标所在工程的源文件的后缀名, 默认为'.cpp'. 如果设定了'FILES', 无需再
## 设定'FILES', 也不起作用.
#FILE_SUFFIX	:= .cpp

## 头文件列表. 默认为'FILES_H=$(wildcard *$(FILE_H_SUFFIX))', 即当前目录下的
## 所有意'$(FILE_H_SUFFIX)'为后缀的文件.
#FILES_H	:=

## 源文件列表. 默认为'FILES=$(wildcard *$(FILE_SUFFIX))', 即当前目录下的所有
## 以'$(FILE_SUFFIX)'为后缀的文. 
#FILES		:=

## DOXYGEN配置文件名(需包含路径), 默认为'Doxyfile'.
#DOXYFILE	:= Doxyfile

## 自动生成(doxygen)文档存放目录. 'make distclean'会清空这个目录,其他文档不要
## 存放在此目录.
#DOCSDIR	:=

## 是否使用默认的编译参数. 默认编译参数, 
##	debug: 		CFLAGS=-Wall -g -D_DEBUG, LDFLAGS= 
##	release:	CFLAGS=-Wall -O3, LDFLAGS=-Wl,-O3 
## 在使用默认参数的情况下, 还可以使用下面的CFLAGS, LDFLAGS, DCFLAGS, DLDFLAGS
## 增加编译参数, 甚至覆盖. 默认为使用编译参数
#DEFAULT_FLAGS	:= 0

## 编译和链接参数设定. 无论C还是C++都使用CFLAGS LDFLAGS, 即CPPFLAGS or CXXFLAGS
## 没有被使用. 注意: 这样是不支持C和C++或其他语言混编的, 当然C代码可以当成C++来
## 编译. 如果是个子项目, 使用父项目的编译参数, 注释掉相应的行. 如果要在父项目的
## 编译参数的基础上增加或覆盖, 如"CFLAGS := $(CFLAGS_PASS) OUR_OWN_FLAGS".
## 如果不想使用父项目或环境变量的参数, 使用如 "CFLAGS := "这样的方式. CFLAGS和
## LDFLAGS用于release编译参数; DCFLAGS和DLDFLAGS用于debug编译参数.
CFLAGS		:= $(CFLAGS_PASS)
DCFLAGS		:= $(DCFLAGS_PASS)
LDFLAGS		:= $(LDFLAGS_PASS)
DLDFLAGS	:= $(DLDFLAGS_PASS)

## 其他. See 'common.cmd.mk' for more.
#CC		:= cc
#CXX		:= c++
#CPP		:= cpp
#LD		:= $(CC) 

## 设定make和make all的默认编译参数为release还是debug. 默认为debug, 记release=0
#release	:= 1

## 需要设定环境变量'MAKE_RULES_DIR'.
include $(MAKE_RULES_DIR)/rules.bin.mk
