import Foundation

class Queue {
    private var list: [Int] = []
    
    init() { list = [] }
    
    func push(x: Int) {
        list.append(x)
    }
    
    func pop() {
        if(empty()) {
            print(-1)
            return
        }
        print(list.removeFirst())
    }
    
    func size() {
        print(list.count)
    }
    
    func empty() -> Bool {
        return list.isEmpty
    }
    
    func front() {
        print(empty() ? -1 : list[0])
    }
    
    func back() {
        print(empty() ? -1 : list[list.count-1])
    }
}

var q = Queue()

let n = Int(readLine()!)!

for _ in 0..<n {
    let command = readLine()!.components(separatedBy: " ")
    if command[0] == "push" {
        q.push(x: Int(command[1])!)
    }
    else if command[0] == "front" {
        q.front()
    }
    else if command[0] == "back" {
        q.back()
    }
    else if command[0] == "size" {
        q.size()
    }
    else if command[0] == "empty" {
        print(q.empty() ? 1 : 0)
    }
    else {
        q.pop()
    }
}
