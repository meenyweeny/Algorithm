import Foundation

var n: Int = 0
var tmp: Int = 0
var num: [Int] = []

func main() {
    n = Int(readLine()!.components(separatedBy: " ")[0])!
    for _ in 0..<n {
        tmp = Int(readLine()!.components(separatedBy: " ")[0])!
        num.append(tmp)
    }
    
    for i in 0..<n {
        for k in 0..<i {
            if(num[k]>num[i]) { num.swapAt(i, k) }
        }
    }
    
    for i in 0..<n {
        print(num[i])
    }
}

main()
