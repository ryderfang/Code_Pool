import Foundation

extension Character {
    var asciiValue: UInt32 {
        return String(self).unicodeScalars.filter{$0.isASCII}.first!.value
    }
}

class Solution {
    func findWords(_ words: [String]) -> [String] {
        let keyboard:[String] = ["qwertyuiop", "asdfghjkl", "zxcvbnm"]
        var result: [String] = []
        for w in words {
            var idx = 0
            for (i, str) in keyboard.enumerated() {
                if str.characters.contains(w.lowercased().characters.first!) {
                    idx = i
                    break;
                }
            }
            var isOneRow = true
            for (i, ch) in w.lowercased().characters.enumerated() where i > 0 {
                if !keyboard[idx].characters.contains(ch) {
                    isOneRow = false
                    break;
                }
            }
            if isOneRow {
                result.append(w)
            }
        }
        return result
    }
}

