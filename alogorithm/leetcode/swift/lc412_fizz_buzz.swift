import Foundation

extension Character {
    var asciiValue: UInt32 {
        return String(self).unicodeScalars.filter{$0.isASCII}.first!.value
    }
}

class Solution {
    func fizzBuzz(_ n: Int) -> [String] {
        var buz: [String] = []
        for v in 1...n {
            if v % 15 == 0 {
                buz.append("FizzBuzz")
            } else if v % 3 == 0 {
                buz.append("Fizz")
            } else if v % 5 == 0 {
                buz.append("Buzz")
            } else {
                buz.append(String(v))
            }
        }
        return buz
    }
}

