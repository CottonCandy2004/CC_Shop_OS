# Help
## ui.h
### ` int ui_choice(char *notice, char **arr, int length)`
**notice**:选项前的提示语<br>
**arr**:选项数组<br>
**length**:选项个数<br>
返回 用户选择的项的编号（0开始）<br>
示例返回值<br>
`0`<br>

### ` int ui_re_choice(char *notice, char **arr, int length, char *result, int result_colour)`
**notice**:选项前的提示语<br>
**arr**:选项数组<br>
**length**:选项个数<br>
**result**:附加内容<br>
**result_colour**:附加内容显示颜色<br>
此为`ui_choice`的衍生函数，允许您在选项的后面附加指定颜色的附加内容<br>
示例返回值<br>
`0`<br>

## ui_terminal.h
### ` void SetColor(UINT uFore, UINT uBack)`
**uFore**:前景色<br>
**uBack**:背景色<br>
设置终端字符的颜色。<br>

### ` void HideConsoleCursor()`
隐藏终端光标<br>

### ` void ShowConsoleCursor()`
显示终端光标<br>

## algorithm.h
### ` void sort_freight(freight *head,freight *tail)`
**head**:排列的头地址<br>
**tail**:排列的尾地址<br>
将指定区间内指针所指向的货物信息按照利润降序排列<br>

### ` char *summonsha(char *str_)`
**str_**:需计算哈希值的字符串<br>
生成给定字符串的哈希值（sha256），返回哈希值字符串。<br>
使用完记得释放内存<br>
示例返回值<br>
`8d969eef6ecad3c29a3a629280e686cf0c3f5d5a86aff3ca12020c923adc6c92`

## freightlib.h
### ` int load_stock_data(freight *stock_data, int *length)`
**stock_data**:需要被导入的数组<br>
**length**:数组内有效项的个数（正常应为0）<br>
从文件加载货物信息至结构体数组，返回操作执行状态<br>
示例返回值<br>
`0`(Success)<br>
`-1`(Read-Write Error)<br>

### ` int save_stock_data(freight *stock_data_head, int *length)`
**stock_data_head**:需要被保存的数组<br>
**length**:需要保存的项的个数<br>
保存结构体数组内的信息至文件，返回操作执行状态<br>
示例返回值<br>
`0`(Success)<br>
`-1`(Read-Write Error)<br>

###  `int silent_save_stock_data(freight *stock_data_head, int *length)`
**stock_data_head**:需要被保存的数组<br>
**length**:需要保存的项的个数<br>
`save_stock_data`的静默版本，不显示保存提示词，返回操作执行状态<br>
示例返回值<br>
`0`(Success)<br>
`-1`(Read-Write Error)<br>