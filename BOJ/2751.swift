//
//  main.swift
//  SwiftAlgorithm
//
//  Created by 이경민 on 2022/08/02.
//

import Foundation

var n: Int = 0
var tmp: Int = 0
var num: [Int] = []

func main() {
    n = Int(readLine()!)!
    for _ in 0..<n {
        num.append(Int(readLine()!)!)
    }
    
    num.sort()
    
    for i in 0..<n {
        print(num[i])
    }
}

main()
