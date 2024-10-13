package com.easy.unique_email_addresses_929;

import java.util.HashSet;
import java.util.Set;

public class SolutionOther extends AbstractSolution {
    public int numUniqueEmails(String[] emails) {

        Set<String> emailSet = new HashSet<>();
        for (String originEmail : emails) {
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

            emailSet.add(localName + "@" + domainName);
        }
        return emailSet.size();
    }
}
