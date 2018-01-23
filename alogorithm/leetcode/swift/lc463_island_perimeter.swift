import Foundation

extension Character {
    var asciiValue: UInt32 {
        return String(self).unicodeScalars.filter{$0.isASCII}.first!.value
    }
}

class Solution {
    func islandPerimeter(_ grid: [[Int]]) -> Int {
        let row = grid.count
        let col = grid[0].count
        
        func isNearToWater(_ x: Int, _ y: Int) -> Bool {
            return (x >= 0 && x < row && y >= 0 && y < col && grid[x][y] == 0)
        }
        
        func isBorder(_ x: Int, _ y: Int) -> Bool {
            return (x == -1 || x == row || y == -1 || y == col)
        }
        
        var count = 0
        for x in 0..<row {
            for y in 0..<col {
                if grid[x][y] == 0 {
                    continue
                }
                if isBorder(x, y+1) || isNearToWater(x, y+1) {
                    count += 1
                }
                if isBorder(x-1, y) || isNearToWater(x-1, y) {
                    count += 1
                }
                if isBorder(x, y-1) || isNearToWater(x, y-1) {
                    count += 1
                }
                if isBorder(x+1, y) || isNearToWater(x+1, y) {
                    count += 1
                }
            }
        }
        return count
    }
}

