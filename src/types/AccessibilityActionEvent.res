type payload = {actionName: string}

include Event.SyntheticEvent({
  type _payload = payload
})
