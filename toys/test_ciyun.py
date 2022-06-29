#! pip3 install jieba
#! pip3 install stylecloud

import jieba
import stylecloud
import sys

def ciyun(fname):
    with open(fname, 'r', encoding='utf-8') as f:
        word_list = jieba.cut(f.read())
        result = " ".join(word_list)
    
    stylecloud.gen_stylecloud(
        text = result,
        size = 512,
        font_path = 'msyh.ttc',
        palette = 'cartocolors.qualitative.Pastel_7',
        gradient = 'horizontal',
        icon_name = 'fab fa-weixin',
        output_name = 'test_ciyun.png')

def main():
    fname = sys.argv[1]
    print(fname)
    ciyun(fname)

if __name__ == '__main__':
    main()