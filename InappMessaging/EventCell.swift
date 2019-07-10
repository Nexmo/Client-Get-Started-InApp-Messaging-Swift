//
//  EventCell.swift
//  InappMessaging
//
//  Created by Paul Ardeleanu on 08/07/2019.
//  Copyright © 2019 Nexmo. All rights reserved.
//

import UIKit
import NexmoClient

class EventCell: UITableViewCell {
    var event: NXMEvent?
    
    @IBOutlet weak var memberNameLabel: UILabel!
    @IBOutlet weak var contentLabel: UILabel!
    @IBOutlet weak var dateLabel: UILabel!
    
    static let dateFormatter = DateFormatter()
    
    
    func updateWith(event: NXMEvent, members: [String: NXMMember]) {
        self.event = event
        memberNameLabel?.text = "-"
        contentLabel?.text = "-"
        
        dateLabel?.text = EventCell.dateFormatter.string(from: event.creationDate)
        
        if let memberEvent = event as? NXMMemberEvent {
            memberNameLabel?.text = memberEvent.user.name
            contentLabel?.text = memberEvent.state.description()
        }
        
        if let textEvent = event as? NXMTextEvent {
            if let member = members[textEvent.fromMemberId] {
                memberNameLabel?.text = member.user.name
            } else {
                memberNameLabel?.text = "Unknown"
            }
            contentLabel?.text = textEvent.text ?? ""
        }
        
    }
}


extension NXMMemberState {
    func description() -> String {
        switch self {
        case .invited:
            return "Invited"
        case .joined:
            return "Joined"
        case .left:
            return "Left"
        @unknown default:
            return "Uknown"
        }
    }
}
