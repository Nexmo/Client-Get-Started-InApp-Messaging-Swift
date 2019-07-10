//
//  NexmoClientExtensions.swift
//  GetStartedAppToPhone
//
//  Created by Paul Ardeleanu on 12/02/2019.
//  Copyright © 2019 Nexmo. All rights reserved.
//

import Foundation
import NexmoClient



extension NXMConnectionStatus {
    func description() -> String {
        switch self {
        case .connected:
            return "Connected"
        case .connecting:
            return "Connecting"
        case .disconnected:
            return "Disconnected"
        @unknown default:
            fatalError()
        }
    }
}

extension NXMConnectionStatusReason {
    func description() -> String {
        switch self {
        case .unknown:
            return "Unknown"
        case .login:
            return "Login"
        case .logout:
            return "Logout"
        case .tokenRefreshed:
            return "Token refreshed"
        case .tokenInvalid:
            return "Token invalid"
        case .tokenExpired:
            return "Token expired"
        case .terminated:
            return "Terminated"
        @unknown default:
            fatalError()
        }
    }
}

extension NXMCallMemberStatus {
    func description() -> String {
        switch self {
        case .dialling:
            return "Dialling"
        case .calling:
            return "Calling"
        case .started:
            return "Started"
        case .answered:
            return "Answered"
        case .cancelled:
            return "Cancelled"
        case .completed:
            return "Completed"
        @unknown default:
            fatalError()
        }
    }
}


extension NXMEventType {
    func description() -> String {
        switch self {
        case .typeGeneral:
            return "typeGeneral"
        case .typeText:
            return "typeText"
        case .typeImage:
            return "typeImage"
        case .typeMessageStatus:
            return "typeMessageStatus"
        case .typeTextTyping:
            return "typeTextTyping"
        case .typeMedia:
            return "typeMedia"
        case .typeMediaAction:
            return "typeMediaAction"
        case .typeMember:
            return "typeMember"
        case .typeSip:
            return "typeSip"
        case .DTMF:
            return "DTMF"
        @unknown default:
            fatalError()
        }
    }
}
