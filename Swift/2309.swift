import Foundation

var height: [Int] = []
var answer: [Int] = []

func solve(nextIndex: Int, count: Int, sum: Int, list: [Int]){
    if count > 7 || sum > 100 { return }
    if count == 7 && sum == 100 {
        answer = list
        return
    }
    var newList = list
    for i in nextIndex..<9 {
        newList.append(height[i])
        solve(nextIndex: i+1, count: count+1, sum: sum+height[i], list: newList)
        newList.removeLast()
    }
}

func main() {
    for _ in 0..<9 {
        height.append(Int(readLine()!)!)
    }
    solve(nextIndex: 0, count: 0, sum: 0, list: [0])
    answer.sort();
    for i in 1...7 {
        print(answer[i])
    }
}

main()
