//
//  ViewController+Interface.swift
//  InappMessaging
//
//  Created by Paul Ardeleanu on 03/07/2019.
//  Copyright © 2019 Nexmo. All rights reserved.
//

import Foundation
import UIKit


enum InterfaceState {
    case notAuthenticated
    case connecting
    case disconnected
    case loggedIn
    case inConversation
}


extension ViewController {
    
    var interfaceState: InterfaceState {
        guard let client = client else {
            return .notAuthenticated
        }
       
        switch client.connectionStatus {
        case .disconnected:
            return .disconnected
        case .connecting:
            return .connecting
        case .connected:
            guard self.conversation != nil else {
                return .loggedIn
            }
            return .inConversation
        @unknown default:
            return .disconnected
        }
    }
    
    func updateInterface() {
        DispatchQueue.main.async { [weak self] in
            guard let self = self else { return }
            
            self.activityIndicator.stopAnimating()
            self.sendMessageButton.alpha = 0
            self.statusLabel.text = ""
            self.messagesTableView.alpha = 0
            self.membersTableView.alpha = 0
            
            switch self.interfaceState {
                
            case .notAuthenticated:
                self.statusLabel.text = "Not Authenticated"
            case .connecting:
                self.activityIndicator.startAnimating()
                self.statusLabel.text = "Connecting"
            case .disconnected:
                self.statusLabel.text = "Disconnected"
            case .loggedIn:
                self.statusLabel.text = "Ready\nLogged in as \(self.user.rawValue)"
            case .inConversation:
                UIView.animate(withDuration: 0.2, animations: { [weak self] in
                    self?.sendMessageButton.alpha = 1
                    self?.messagesTableView.alpha = 1
                    self?.membersTableView.alpha = 1
                })
                self.statusLabel.text = "In Conversation"
            }
            
        }
    }
    
    
}
