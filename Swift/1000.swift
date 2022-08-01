//
//  1000.swift
//  SwiftAlgorithm
//
//  Created by 이경민 on 2022/08/02.
//

import Foundation

let input = readLine()!
let arr = input.components(separatedBy: " ").map({ Int($0)! })
print(arr[0]+arr[1])
