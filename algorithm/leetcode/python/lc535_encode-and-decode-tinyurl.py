import hashlib
import string

class Codec:
    @staticmethod
    def alpha_digit():
        return list(string.ascii_lowercase) + list(map(lambda x: str(x), list(range(0, 10)))) + list(string.ascii_uppercase)

    def __init__(self):
        self.short_urls = {}
        self.origin_urls = {}
        self.chars = Codec.alpha_digit()
    
    def encode(self, longUrl):
        """Encods a URL to a shortened URL.
        
        :type longUrl: str
        :rtype: str
        """
        if longUrl in self.short_urls:
            return self.short_urls[longUrl]
        hl = hashlib.md5()
        hl.update(longUrl.encode(encoding='utf-8'))
        print(hl.hexdigest())
        md5 = hl.hexdigest()
        res_url = []
        for i in range(0, 4):
            sub = md5[i * 8 : i * 8 + 8]
            print(sub)
            hex_long = 0x3FFFFFFF & int(sub, 16)
            out_char = ''
            for _ in range(0, 6):
                index = 0x0000003D & hex_long
                out_char += self.chars[index]
                hex_long = hex_long >> 5
            res_url.append(out_char)
            if not out_char in self.origin_urls:
                self.short_urls[longUrl] = out_char
                self.origin_urls[out_char] = longUrl
                break;
        return self.short_urls[longUrl]

    def decode(self, shortUrl):
        """Decodes a shortened URL to its original URL.
        
        :type shortUrl: str
        :rtype: str
        """
        return self.origin_urls[shortUrl]
        

# Your Codec object will be instantiated and called as such:
url = 'https://leetcode.com/problems/design-tinyurl'
codec = Codec()
print(codec.encode(url))
print(codec.decode(codec.encode(url)))

