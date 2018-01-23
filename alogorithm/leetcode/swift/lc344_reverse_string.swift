import Foundation

extension Character {
    var asciiValue: UInt32 {
        return String(self).unicodeScalars.filter{$0.isASCII}.first!.value
    }
}

class Solution {
    func reverseString(_ s: String) -> String {
        var arr: [Character] = []
        if s.startIndex == s.endIndex {
            return ""
        }
        var idx = s.index(before: s.endIndex)
        while idx != s.startIndex {
            arr.append(s[idx])
            idx = s.index(before: idx)
        }
        arr.append(s[idx])
        return String(arr)
    }
}

