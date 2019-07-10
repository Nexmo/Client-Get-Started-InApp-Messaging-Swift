//
//  ViewController+Nexmo.swift
//  InappMessaging
//
//  Created by Paul Ardeleanu on 10/07/2019.
//  Copyright © 2019 Nexmo. All rights reserved.
//

import Foundation
import UIKit
import NexmoClient



//MARK:- Conversation

extension ViewController {
    
    func getConversation() {
        client?.getConversationWithId(Constant.conversationId, completion: { [weak self] (error, conversation) in
            print("📮📮📮 getConversationWithId")
            print("    ⌞ error: \(String(describing: error?.localizedDescription))")
            print("    ⌞ conversation: \(String(describing: conversation))")
            print("    ⌞ conversation id: \(String(describing: conversation?.conversationId))")
            self?.conversation = conversation
            self?.updateInterface()
            self?.getMembers()
        })
    }
    
    func getMembers() {
        members = [:]
        guard let conversation = self.conversation else { return }
        print("📮📮📮 conversation members:")
        if let myMember = conversation.myMember {
            print("    ⌞ myMember: \(String(describing: myMember.memberId)) \(String(describing: myMember.user.name))")
            setEventsController()
            members[myMember.memberId] = myMember
        } else {
            joinConversation()
            return
        }
        
        conversation.otherMembers?.forEach({ member in
            print("    ⌞ otherMember: \(String(describing: member.memberId)) \(String(describing: member.user.name))")
            members[member.memberId] = member
        })
        
        DispatchQueue.main.async { [weak self] in
            self?.navigationItem.rightBarButtonItem = UIBarButtonItem(title: "Members", style: .done, target: self, action: Selector(("showMembers")))
            self?.membersTableView.reloadData()
        }
    }
    
    func joinConversation() {
        self.conversation?.join(completion: { [weak self] (error, member) in
            print("📮📮📮 joinConversation")
            print("    ⌞ error: \(String(describing: error?.localizedDescription))")
            print("    ⌞ conversation: \(String(describing: member))")
            print("    ⌞ conversation id: \(String(describing: member?.user.name))")
            self?.getMembers()
        })
    }
    
    
    func setEventsController() {
        let eventTypes: Set<NSNumber> = [
            NSNumber(value: NXMEventType.typeGeneral.rawValue),
            NSNumber(value: NXMEventType.typeText.rawValue),
            NSNumber(value: NXMEventType.typeImage.rawValue),
            NSNumber(value: NXMEventType.typeMessageStatus.rawValue),
            NSNumber(value: NXMEventType.typeTextTyping.rawValue),
            NSNumber(value: NXMEventType.typeMedia.rawValue),
            NSNumber(value: NXMEventType.typeMediaAction.rawValue),
            NSNumber(value: NXMEventType.typeMember.rawValue),
            NSNumber(value: NXMEventType.typeSip.rawValue)]
        
        let eventsController = conversation?.eventsController(withTypes: eventTypes, andDelegate: self)
        self.events = eventsController?.events ?? []
        print("events: \(String(describing: events))")
        eventsController?.loadEarlierEvents(withMaxAmount: 100, completion: { (error) in
            print("📨📨📨 load Conversation history:")
            print("    ⌞ error: \(String(describing: error?.localizedDescription))")
        })
    }
    
}





//MARK:- Nexmo Client Delegate

extension ViewController: NXMClientDelegate {
    
    func connectionStatusChanged(_ status: NXMConnectionStatus, reason: NXMConnectionStatusReason) {
        print("👁👁👁 connectionStatusChanged - status: \(status.description()) - reason: \(reason.description())")
        updateInterface()
        
        if status == .connected {
            getConversation()
        }
    }
    
}



//MARK: - Nexmo ConversationEventsController Delegate
extension ViewController: NXMConversationEventsControllerDelegate {
    
    func nxmConversationEventsControllerDidChangeContent(_ controller: NXMConversationEventsController) {
        print("📣📣📣 Conversation history change:")
        print("events: \(String(describing: controller.events))")
        controller.events.forEach { (event) in
            print("   📣 Event:")
            print("        ⌞ creationDate: \(event.creationDate)")
            print("        ⌞ type: \(event.type.description())")
            
        }
        self.events.append(contentsOf: controller.events)
        DispatchQueue.main.async { [weak self] in
            self?.messagesTableView.reloadData()
        }
    }
    
}

