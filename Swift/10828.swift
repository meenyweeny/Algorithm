import Foundation

class Stack {
    private var list: [Int] = []
    
    func empty() {
        print(list.isEmpty ? "1" : "0")
    }
    
    func size() {
        print(list.count)
    }
    
    func top() {
        print(list.last ?? "-1")
    }
    
    func pop() {
        print(list.popLast() ?? "-1")
    }
    
    func push(_ element: Int) {
        list.append(element)
    }
}


let n = Int(readLine()!)!
var st = Stack()

var input: [String] = []
var command = ""
var x = 0

for _ in 0..<n {
    input = readLine()!.components(separatedBy: " ")
    command = input[0]
    
    switch command {
    case "push":
        x = Int(input[1])!
        st.push(x)
    case "pop":
        st.pop()
    case "top":
        st.top()
    case "size":
        st.size()
    case "empty":
        st.empty()
    default: print("")
    }
}
