# Help
## ui.h
### ` int ui_choice(char *notice, char **arr, int length)`
**notice**:ѡ��ǰ����ʾ��
**arr**:ѡ������
**length**:ѡ�����
���� �û�ѡ�����ı�ţ�0��ʼ��
ʾ������ֵ
`0`

### ` int ui_re_choice(char *notice, char **arr, int length, char *result, int result_colour)`
**notice**:ѡ��ǰ����ʾ��
**arr**:ѡ������
**length**:ѡ�����
**result**:��������
**result_colour**:����������ʾ��ɫ
��Ϊ`ui_choice`��������������������ѡ��ĺ��渽��ָ����ɫ�ĸ�������
ʾ������ֵ
`0`

## ui_terminal.h
### ` void SetColor(UINT uFore, UINT uBack)`
**uFore**:ǰ��ɫ
**uBack**:����ɫ
�����ն��ַ�����ɫ��

### ` void HideConsoleCursor()`
�����ն˹��

### ` void ShowConsoleCursor()`
��ʾ�ն˹��

## algorithm.h
### ` void sort_freight(freight *head,freight *tail)`
**head**:���е�ͷ��ַ
**tail**:���е�β��ַ
��ָ��������ָ����ָ��Ļ�����Ϣ��������������

### ` char *summonsha(char *str_)`
**str_**:������ϣֵ���ַ���
���ɸ����ַ����Ĺ�ϣֵ��sha256�������ع�ϣֵ�ַ�����
ʹ����ǵ��ͷ��ڴ�
ʾ������ֵ
`8d969eef6ecad3c29a3a629280e686cf0c3f5d5a86aff3ca12020c923adc6c92`

## freightlib.h
### ` int load_stock_data(freight *stock_data, int *length)`
**stock_data**:��Ҫ�����������
**length**:��������Ч��ĸ���������ӦΪ0��
���ļ����ػ�����Ϣ���ṹ�����飬���ز���ִ��״̬
ʾ������ֵ
`0`(Success)
`-1`(Read-Write Error)

### ` int save_stock_data(freight *stock_data_head, int *length)`
**stock_data_head**:��Ҫ�����������
**length**:��Ҫ�������ĸ���
����ṹ�������ڵ���Ϣ���ļ������ز���ִ��״̬
ʾ������ֵ
`0`(Success)
`-1`(Read-Write Error)

###  `int silent_save_stock_data(freight *stock_data_head, int *length)`
**stock_data_head**:��Ҫ�����������
**length**:��Ҫ�������ĸ���
`save_stock_data`�ľ�Ĭ�汾������ʾ������ʾ�ʣ����ز���ִ��״̬
ʾ������ֵ
`0`(Success)
`-1`(Read-Write Error)