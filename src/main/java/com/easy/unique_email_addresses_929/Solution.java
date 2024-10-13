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
        String localName = "", domainName = "";

        StringBuilder builder = new StringBuilder();
        boolean nowIsLocal = true;
        for (int index = 0; index < originEmail.length(); index++) {
            char c = originEmail.charAt(index);
            if (nowIsLocal) {
                switch (c) {
                    case '.' -> {
                        continue;
                    }
                    case '+', '@' -> {
                        localName = builder.toString();
                        nowIsLocal = false;
                    }
                    default -> builder.append(c);
                }
            }

            if (c == '@') {
                domainName = originEmail.substring(index + 1);
                break;
            }
        }

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