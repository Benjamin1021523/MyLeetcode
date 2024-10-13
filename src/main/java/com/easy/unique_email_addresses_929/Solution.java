package com.easy.unique_email_addresses_929;

import java.util.HashSet;
import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Set;

class Solution extends AbstractSolution {
    public int numUniqueEmails(String[] emails) {
        domainEmailSetMap = new LinkedHashMap<>();
        for (String originEmail : emails) {
            addEmail(originEmail);
        }
        return getCount();
    }

    private Map<String, Set<String>> domainEmailSetMap;

    private void addEmail(String originEmail) {
        String[] splitStr = originEmail.split("@");

        int firstPlusIndex = splitStr[0].indexOf("+");

        String localName;
        if (firstPlusIndex == -1) {
            localName = splitStr[0];
        } else {
            localName = splitStr[0].substring(0, firstPlusIndex);
        }
        localName = localName.replace(".", "");

        String domainName = splitStr[1];

        Set<String> localNameSet = domainEmailSetMap.getOrDefault(domainName, new HashSet<>());
        localNameSet.add(localName);
        domainEmailSetMap.put(domainName, localNameSet);
    }

    private int getCount() {
        int count = 0;

        for (Set<String> localNameSet : domainEmailSetMap.values()) {
            count += localNameSet.size();
        }

        return count;
    }
}