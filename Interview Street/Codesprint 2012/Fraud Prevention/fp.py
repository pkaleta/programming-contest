import sys
import re

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
        self.vs = []

    def __str__(self):
        return ", ".join([self.id, self.dealId, self.email, self.street, self.city, self.state, self.zip, self.creditCard])

deals = {}
visited = set([])

def dfs(order, ret):
    if not order in visited:
        ret.add(order)
        visited.add(order)
        for order2 in deals[order.dealId]:
            if not order2 in visited and ((order.email == order2.email and order.dealId == order2.dealId and order.creditCard != order2.creditCard) or (order.street == order2.street and order.city == order2.city and order.state == order2.state and order.zip == order2.zip and order.dealId == order2.dealId and order.creditCard != order2.creditCard)):
                ret.add(order2)
                dfs(order2, ret)
        return ret
    return ret

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
        if deals.has_key(order.dealId):
            deals[order.dealId].append(order)
        else:
            deals[order.dealId] = [order]

    fraudulent = set([])
    for dealId in deals.keys():
        for order in deals[dealId]:
                orders = dfs(order, set([order]))
                if len(orders) > 1:
                    fraudulent = fraudulent.union(orders)

    print ",".join(map(str, (sorted(map(lambda order: int(order.id), list(fraudulent))))))
