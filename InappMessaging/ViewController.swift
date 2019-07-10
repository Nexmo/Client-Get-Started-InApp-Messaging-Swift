//
//  ViewController.swift
//  InappMessaging
//
//  Created by Paul Ardeleanu on 03/07/2019.
//  Copyright © 2019 Nexmo. All rights reserved.
//

import UIKit
import NexmoClient



class ViewController: UIViewController {
    
    @IBOutlet weak var activityIndicator: UIActivityIndicatorView!
    @IBOutlet weak var statusLabel: UILabel!
    @IBOutlet weak var sendMessageButton: UIButton!
    @IBOutlet weak var messagesTableView: UITableView!
    @IBOutlet weak var messagesLeadingConstraint: NSLayoutConstraint!
    @IBOutlet weak var membersTableView: UITableView!
    
    var user: User!
    var client: NXMClient?
    var conversation: NXMConversation?
    var member: NXMMember?
    
    var members = [String: NXMMember]()
    var events = [NXMEvent]()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        navigationItem.leftBarButtonItem = UIBarButtonItem(title: "Logout", style: .done, target: self, action: #selector(NXMClient.logout))
        
        messagesTableView.dataSource = self
        messagesTableView.delegate = self
        EventCell.dateFormatter.dateFormat = "MMM dd, HH:mm"
        
        membersTableView.dataSource = self
        membersTableView.delegate = self
        
        updateInterface()
        setupNexmoClient()
    }
    
    @objc func showMembers() {
        messagesLeadingConstraint.constant = (messagesLeadingConstraint.constant == 0) ? -(membersTableView.bounds.size.width) : 0
        UIView.animate(withDuration: 0.2) {
            self.view.layoutIfNeeded()
        }
    }
    
    func setupNexmoClient() {
        client = NXMClient(token: user.token)
        client?.setDelegate(self)
        client?.login()
    }
    
    @objc func logout() {
        client?.logout()
        navigationController?.popViewController(animated: true)
    }
    
    @IBAction func sendMessage(_ sender: Any) {
        send(message: "Hello World")
    }
    
    func send(message: String) {
        conversation?.sendText(message, completion: { (error) in
            print("🔤🔤🔤 sendText: \(message)")
            print("    ⌞ error: \(String(describing: error?.localizedDescription))")
        })
    }
    
}



//MARK:- TableView Data Source & Delegate

extension ViewController: UITableViewDataSource, UITableViewDelegate {
    
    var membersArray: [NXMMember] {
        return Array(members.values)
    }
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return tableView == messagesTableView ? events.count : members.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        if tableView == messagesTableView {
            let cell = tableView.dequeueReusableCell(withIdentifier: "MessageCell") as? EventCell
            cell?.updateWith(event: events[indexPath.row], members: members)
            return cell ?? UITableViewCell()
        }
        let cell = tableView.dequeueReusableCell(withIdentifier: "MemberCell")!
        cell.textLabel?.text = membersArray[indexPath.row].user.name
        cell.detailTextLabel?.text = membersArray[indexPath.row].memberId
        cell.detailTextLabel?.numberOfLines = 0
        return cell
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        tableView.deselectRow(at: indexPath, animated: true)
        if tableView == membersTableView {
            return
        }
        let event = events[indexPath.row]
        print("   📣 Event:")
        print("        ⌞ creationDate: \(event.creationDate)")
        print("        ⌞ type:         \(event.type.description())")
        print("        ⌞ fromMemberId: \(event.fromMemberId)")
    }
    
}




