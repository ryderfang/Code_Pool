import Foundation

extension Character {
    var asciiValue: UInt32 {
        return String(self).unicodeScalars.filter{$0.isASCII}.first!.value
    }
}

class Solution {
    func isContinus(_ lhs: Character, _ rhs: Character) -> Bool {
        if (lhs == "z" && rhs == "a") ||
            (lhs.asciiValue + 1 == rhs.asciiValue) {
            return true
        }
        return false
    }
    
    func findSubstringInWraproundString(_ str: String) -> Int {
        let alpha = (97...122).map({
            String(UnicodeScalar($0))
        })
        var dic: [String: Int] = [:]
        for v in alpha {
            dic[v] = 0
        }
        var p = str.startIndex
        while p != str.endIndex {
            var q: String.Index? = p
            dic[String(str[p])] = max(1, dic[String(str[p])]!)
            var offset = 1
            while true {
                q = str.index(after: q!)
                if q == str.endIndex {
                    break;
                }
                if (!isContinus(str[str.index(before: q!)], str[q!])) {
                    break;
                }
                dic[String(str[q!])] = max(offset + 1, dic[String(str[q!])]!)
                offset += 1
            }
            p = q!
        }
        let total = dic.values.reduce(0, {$0 + $1})
        return total
    }
}

