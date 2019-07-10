#  In-App Messaging


## Setup


### Create an app

    nexmo app:create "My Conversation App" http://example.com/answer http://example.com/event --keyfile=private.key

Make a note of the application id returned.


### Create 2 users

    nexmo user:create name="Jane"
    nexmo user:create name="Joe"


### Generate JWTs for users

Replace `YOUR_APP_ID` with the application id returned during first step.

    nexmo jwt:generate ./private.key sub=Jane exp=$(($(date +%s)+86400)) acl='{"paths":{"/v1/users/**":{},"/v1/conversations/**":{},"/v1/sessions/**":{},"/v1/devices/**":{},"/v1/image/**":{},"/v3/media/**":{},"/v1/applications/**":{},"/v1/push/**":{},"/v1/knocking/**":{}}}' application_id=YOUR_APP_ID

    nexmo jwt:generate ./private.key sub=Joe exp=$(($(date +%s)+86400)) acl='{"paths":{"/v1/users/**":{},"/v1/conversations/**":{},"/v1/sessions/**":{},"/v1/devices/**":{},"/v1/image/**":{},"/v3/media/**":{},"/v1/applications/**":{},"/v1/push/**":{},"/v1/knocking/**":{}}}' application_id=YOUR_APP_ID

Copy and paste the 2 JWTs into `Constants.swift`.


### Create conversation

    nexmo conversation:create display_name="Nexmo Chat"
    
Use conversation id into `Constants.swift`.

