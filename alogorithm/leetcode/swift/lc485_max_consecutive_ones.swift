import Foundation

extension Character {
    var asciiValue: UInt32 {
        return String(self).unicodeScalars.filter{$0.isASCII}.first!.value
    }
}

class Solution {
    func findMaxConsecutiveOnes(_ nums: [Int]) -> Int {
        var maxCount = 0
        var localMax = 0
        for x in nums {
            if x == 1 {
                localMax += 1
            } else {
                maxCount = max(maxCount, localMax)
                localMax = 0
            }
        }
        maxCount = max(maxCount, localMax)
        return maxCount
    }
}

