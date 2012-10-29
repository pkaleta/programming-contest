import sys
import re

emailHash = {}
addressHash = {}

def normalizeCity(city):
    cityParts = city.lower().split()
    return " ".join(map(lambda part: re.sub("st\.", "street", re.sub("rd\.", "road", part)), cityParts))

def normalizeEmail(email):
    local, domain = email.strip().split("@")
    local = re.sub("\+.*", "", re.sub("\.", "", local.lower()))
    return local + "@" + domain.lower()

def normalizeStreet(street):
    streetParts = street.lower().split()
    return " ".join(map(lambda part: re.sub("st\.", "street", re.sub("rd\.", "road", part)), streetParts))

def normalizeState(state):
    states = {"illinois":"il",
              "new york":"ny",
              "california":"ca"}
    state = state.strip().lower()
    if states.has_key(state):
        return states[state]
    else:
        return state

def normalizeZip(zip):
    return zip.strip().lower()

class Order(object):
    def __init__(self, id, dealId, email, street, city, state, zip, creditCard):
        self.id = id
        self.dealId = dealId
        self.email = normalizeEmail(email)
        self.street = normalizeStreet(street)
        self.city = normalizeCity(city)
        self.state = normalizeState(state)
        self.zip = normalizeZip(zip)
        self.creditCard = creditCard

    def __str__(self):
        return ", ".join([self.id, self.dealId, self.email, self.street, self.city, self.state, self.zip, self.creditCard])

def insertEmailHash(order):
    emailHashKey = order.email + "," + order.dealId
    if emailHash.has_key(emailHashKey):
        creditHash = emailHash[emailHashKey]
        if creditHash.has_key(order.creditCard):
            ids = creditHash[order.creditCard]
            ids.append(order.id)
            creditHash[order.creditCard] = ids
        else:
            creditHash[order.creditCard] = [order.id]
    else:
        emailHash[emailHashKey] = {order.creditCard : [order.id]}

def insertAddressHash(order):
    addressHashKey = ",".join([order.street, order.city, order.state, order.zip, order.dealId])
    if addressHash.has_key(addressHashKey):
        creditHash = addressHash[addressHashKey]
        if creditHash.has_key(order.creditCard):
            ids = creditHash[order.creditCard]
            ids.append(order.id)
            creditHash[order.creditCard] = ids
        else:
            creditHash[order.creditCard] = [order.id]
    else:
        addressHash[addressHashKey] = {order.creditCard : [order.id]}

def checkFraudulent(hashed):
    fraudulent = set([])
    for creditHash in hashed.values():
        if len(creditHash) > 1:
            for ids in creditHash.values():
                fraudulent = fraudulent.union(ids)
    return fraudulent

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    for i in xrange(n):
        orderParts = sys.stdin.readline().strip().split(",")
        order = Order(orderParts[0], \
                          orderParts[1], \
                          orderParts[2], \
                          orderParts[3], \
                          orderParts[4], \
                          orderParts[5], \
                          orderParts[6], \
                          orderParts[7])
#        print "********", order
        insertEmailHash(order)
        insertAddressHash(order)

    fraudulent = checkFraudulent(emailHash).union(checkFraudulent(addressHash))

    print ",".join(map(str, (sorted(map(int, list(fraudulent))))))
