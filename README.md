
# AES 使用样例

## 说明

使用的 aes.c 和 aes.h 是从网站 https://www.aescrypt.com/ 下载的 aescrypt-3.13.tgz 中提取出来的两个文件。



在 aes.c 中，对于表和S-box等，给出了两种实现，通过宏开关 FIXED_TABLES 进行选择：
1. FIXED_TABLES方式，所有表格直接给出，不用在程序运行时进行计算；
2. 表预计算的方式，使用了对数表的方式来实现有限域的乘法操作，在程序运行时生成各种表。
