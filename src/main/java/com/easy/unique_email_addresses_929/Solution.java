package com.easy.unique_email_addresses_929;

import java.util.*;

class Solution extends AbstractSolution {
    public int numUniqueEmails(String[] emails) {
        domainEmailSetMap = new HashMap<>();
        uniqueEmailCount = 0;

        for (String originEmail : emails) {
            addEmail(originEmail);
        }
        return getCount();
    }

    private int uniqueEmailCount;
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
        boolean isNewEmail = localNameSet.add(localName);
        if (isNewEmail) {
            ++uniqueEmailCount;
        }
        domainEmailSetMap.put(domainName, localNameSet);
    }

    private int getCount() {
        return uniqueEmailCount;
    }
}