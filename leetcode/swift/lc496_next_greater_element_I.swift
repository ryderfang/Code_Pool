mport Foundation

extension Character {
    var asciiValue: UInt32 {
        return String(self).unicodeScalars.filter{$0.isASCII}.first!.value
    }
}

class Solution {
    func nextGreaterElement(_ findNums: [Int], _ nums: [Int]) -> [Int] {
        var result: [Int] = []
        for p in findNums {
            var findP = false
            var hasFound = false
            for q in nums {
                if q == p {
                    findP = true
                }
                if q > p && findP {
                    result.append(q)
                    hasFound = true
                    break;
                }
            }
            if !hasFound {
                result.append(-1)
            }
        }
        return result
    }
}

