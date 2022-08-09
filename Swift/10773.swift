import Foundation

let k = Int(readLine()!)!
var x: Int = 0
var st: [Int] = []
var sum: Int = 0

for _ in 0..<k {
    x = Int(readLine()!)!
    if x==0 {
        sum -= st.popLast() ?? 0
        continue
    }
    sum+=x
    st.append(x)
}

print(sum)
