import Foundation

class Solution {
    func findComplement(_ num: Int) -> Int {
        let bstr = String(num, radix:2)
        let dstr = String(bstr.characters.map {
            $0 == "0" ? "1" : "0"
        })
        return Int(dstr, radix:2)!
    }
}

