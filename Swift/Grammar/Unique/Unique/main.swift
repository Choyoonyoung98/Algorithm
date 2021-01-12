//
//  main.swift
//  Unique
//
//  Created by 조윤영 on 2021/01/02.
//

import Foundation

func solution() {
    var word: String = "acdfff"
    print(word.unique())
    var words: [String] = ["a", "a", "b" ]
    print(words.unique())
}

solution()

extension Sequence where Iterator.Element: Hashable {
    func unique() -> [Iterator.Element] {
        var seen: [Iterator.Element: Bool] = [:]
        return self.filter { seen.updateValue(true, forKey: $0) == nil }
    }
}
