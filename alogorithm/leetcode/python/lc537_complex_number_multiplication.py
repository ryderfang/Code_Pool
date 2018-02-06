class Solution(object):
    def complexNumberMultiply(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        p = a.index('+')
        ra = int(a[:p])
        ia = int(a[p+1:-1])
        p = b.index('+')
        rb = int(b[:p])
        ib = int(b[p+1:-1])
        '''
        (ra + ia * i) * (rb + ib * i) =
            (ra * rb - ia * ib) + (ra * ib + rb * ia)i
        ''' 
        rp = ra * rb - ia * ib
        ip = ra * ib + rb * ia
        return str(rp) + "+" + str(ip) +"i"
