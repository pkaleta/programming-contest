def genPerms(notUsed):
    if len(notUsed) == 1:
        return [notUsed]

    ret = []
    for i in xrange(len(notUsed)):
        perms = genPerms(notUsed[:i] + notUsed[i+1:])
        for j in xrange(len(perms)):
            ret.append([notUsed[i]]+perms[j])
    return ret


print genPerms([1,2,3])


