//
//  Contants.swift
//  InappMessaging
//
//  Created by Paul Ardeleanu on 03/07/2019.
//  Copyright © 2019 Nexmo. All rights reserved.
//

import Foundation


// See README.md for instructions on how to create the tokens and conversation id required below


enum User: String {
    case jane = "Jane"
    case joe = "Joe"
    
    var token: String {
        switch self {
        case .jane:
            return "" //TODO: swap with a token for Jane
        case .joe:
            return "" //TODO: swap with a token for Joe
        }
    }
}



enum Constant {
    static var conversationId = "" //TODO: swap with a conversation id
}


