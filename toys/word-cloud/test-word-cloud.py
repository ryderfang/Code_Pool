#! pip3 install jieba
#! pip3 install wordcloud

import matplotlib.pyplot as plt
import jieba
import wordcloud
from wordcloud import WordCloud, ImageColorGenerator, STOPWORDS
import numpy as np
from PIL import Image
import sys

def ciyun(fname):
    with open(fname, 'r', encoding = 'utf-8') as f:
        textfile= f.read()
    wordlist = jieba.lcut(textfile)
    space_list = ' '.join(wordlist)
    backgroud = np.array(Image.open('qq.png')) 

    stop_words = ['x', '次', '星', 'T8', 'T9', 'T10', 'T11', 'T12']
	
    wc = WordCloud(width=512, height=512,
			background_color='white',
	        mode='RGB', 
			mask=backgroud,
			max_words=500,
			stopwords=set(stop_words),
			font_path='msyh.ttc',
			max_font_size=150,
			relative_scaling=0.6,
			random_state=50, 
			scale=2
			).generate(space_list) 
			
    image_color = ImageColorGenerator(backgroud)
    wc.recolor(color_func=image_color)
	
    plt.imshow(wc)
    plt.axis('off')
    plt.show()
    wc.to_file('test-word-cloud.jpg')

def main():
    fname = sys.argv[1]
    print(fname)
    ciyun(fname)
 
if __name__ == '__main__':
    main()