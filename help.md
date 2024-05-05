# Help
## ui.h
### ` int ui_choice(char *notice, char **arr, int length)`
**notice**:ѡ��ǰ����ʾ��<br>
**arr**:ѡ������<br>
**length**:ѡ�����<br>
���� �û�ѡ�����ı�ţ�0��ʼ��<br>
ʾ������ֵ<br>
`0`<br>

### ` int ui_re_choice(char *notice, char **arr, int length, char *result, int result_colour)`
**notice**:ѡ��ǰ����ʾ��<br>
**arr**:ѡ������<br>
**length**:ѡ�����<br>
**result**:��������<br>
**result_colour**:����������ʾ��ɫ<br>
��Ϊ`ui_choice`��������������������ѡ��ĺ��渽��ָ����ɫ�ĸ�������<br>
ʾ������ֵ<br>
`0`<br>

## ui_terminal.h
### ` void SetColor(UINT uFore, UINT uBack)`
**uFore**:ǰ��ɫ<br>
**uBack**:����ɫ<br>
�����ն��ַ�����ɫ��<br>

### ` void HideConsoleCursor()`
�����ն˹��<br>

### ` void ShowConsoleCursor()`
��ʾ�ն˹��<br>

## algorithm.h
### ` void sort_freight(freight *head,freight *tail)`
**head**:���е�ͷ��ַ<br>
**tail**:���е�β��ַ<br>
��ָ��������ָ����ָ��Ļ�����Ϣ��������������<br>

### ` char *summonsha(char *str_)`
**str_**:������ϣֵ���ַ���<br>
���ɸ����ַ����Ĺ�ϣֵ��sha256�������ع�ϣֵ�ַ�����<br>
ʹ����ǵ��ͷ��ڴ�<br>
ʾ������ֵ<br>
`8d969eef6ecad3c29a3a629280e686cf0c3f5d5a86aff3ca12020c923adc6c92`

## freightlib.h
### ` int load_stock_data(freight *stock_data, int *length)`
**stock_data**:��Ҫ�����������<br>
**length**:��������Ч��ĸ���������ӦΪ0��<br>
���ļ����ػ�����Ϣ���ṹ�����飬���ز���ִ��״̬<br>
ʾ������ֵ<br>
`0`(Success)<br>
`-1`(Read-Write Error)<br>

### ` int save_stock_data(freight *stock_data_head, int *length)`
**stock_data_head**:��Ҫ�����������<br>
**length**:��Ҫ�������ĸ���<br>
����ṹ�������ڵ���Ϣ���ļ������ز���ִ��״̬<br>
ʾ������ֵ<br>
`0`(Success)<br>
`-1`(Read-Write Error)<br>

###  `int silent_save_stock_data(freight *stock_data_head, int *length)`
**stock_data_head**:��Ҫ�����������<br>
**length**:��Ҫ�������ĸ���<br>
`save_stock_data`�ľ�Ĭ�汾������ʾ������ʾ�ʣ����ز���ִ��״̬<br>
ʾ������ֵ<br>
`0`(Success)<br>
`-1`(Read-Write Error)<br>