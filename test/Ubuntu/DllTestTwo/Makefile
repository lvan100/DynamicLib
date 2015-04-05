#########################################################
#		通用 Makefile 模板			#
#		作者：梁欢				#
#		日期：2014/11/18			#
#		邮箱：lvan100@yeah.net			#
#########################################################

#! 设置工作目录变量
## 一般需要用户设置
DIR_INC = ../../../src
DIR_SRC = ../../../test
DIR_OBJ = ../obj
DIR_BIN = ../bin

$(shell mkdir -p ${DIR_OBJ})
$(shell mkdir -p ${DIR_BIN})

#! 设置附加目录、库
## 一般需要用户设置
EXT_INC = -I$(DIR_INC)
EXT_LIB = 

#! 设置当前模块名称
## 一般需要用户设置
MODULE = DllTestTwo
TARGET = $(MODULE)

#! 设置编译器的参数
## 一般需要用户设置
CC := gcc $(EXT_INC)
#CFLAGS := -lpthread

#! 设置默认编译类型
## 一般需要用户设置
.PHONY:default
default:so

#! 设置各种可能用到的编译目标种类和名称
BIN_TARGET = ${DIR_BIN}/$(TARGET)
LIB_TARGET = ${DIR_BIN}/$(TARGET).a
SO_TARGET = ${DIR_BIN}/$(TARGET).so

#! 设置编译和连接的CPP/C的源码文件
SRC = DllTestTwo.cpp

#! 设置由源码文件生成的OBJ目标文件
CPP_OBJ = $(patsubst %.cpp,${DIR_OBJ}/%.o,$(notdir ${SRC}))
C_OBJ = $(patsubst %.c,${DIR_OBJ}/%.o,$(notdir ${C_SRC}))
OBJ = $(C_OBJ) $(CPP_OBJ)

#! 编译静态连接库
.PHONY:lib
lib:$(LIB_TARGET)
$(LIB_TARGET):${OBJ}
	$(AR) -r $(LIB_TARGET) ${OBJ}

#! 编译动态连接库
.PHONY:so
so:$(SO_TARGET)
${SO_TARGET}:${OBJ}
	$(CC) -shared $(OBJ) -o $@ $(EXT_LIB)

#! 编译应用程序
.PHONY:bin
bin:$(BIN_TARGET)
#! 使用宏定义开关"main"函数
CFLAGS += -D TARGET_BIN
${BIN_TARGET}:${OBJ}
	$(CC) $(OBJ) -o $@ $(EXT_LIB)

#! 设置生成目标文件
${DIR_OBJ}/%.o:${DIR_SRC}/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(EXT_LIB)

#! 设置生成目标文件
${DIR_OBJ}/%.o:${DIR_SRC}/%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(EXT_LIB)

#! 清除所有目标文件	
.PHONY:clean
clean:
	find ${DIR_OBJ} -name "*.o" -exec rm -rf {} \;
