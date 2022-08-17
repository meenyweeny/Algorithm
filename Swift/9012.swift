import Foundation

var input: String
let n = Int(readLine()!)!
var size: Int = 0

for _ in 0..<n {
    input = readLine()!
    
    for i in 0..<input.count {
        if input[input.index(input.startIndex, offsetBy: i)] == "(" {
            size+=1
        }
        else {
            size-=1
            if size == -1 {
                break
            }
        }
    }
    print(size == 0 ? "YES" : "NO")
    size = 0
}
