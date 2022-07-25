import Foundation

var n: Int = 0
var m: Int = 0
var cards: [Int] = []

func main() {
    let input = readLine()!.components(separatedBy: " ").map { Int($0)! }
    cards = readLine()!.components(separatedBy: " ").map { Int($0)! }
    n = input[0]
    m = input[1]
    
    var answer: Int = 0
    
    for i in 0...n-3 {
        for j in i+1...n-2 {
            for k in j+1...n-1 {
                let sum = cards[i]+cards[j]+cards[k]
                if sum <= m { answer = max(answer, sum) }
            }
        }
    }
    
    print(answer)
}

main()
