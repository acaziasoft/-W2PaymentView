//
//  CreditCardObject.h
//  VapeBlock
//
//  Created by mac on 8/8/16.
//  Copyright © 2016 Tarar. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AddressObject.h"

enum CardType {
    OtherCard=0,
    MasterCard,
    Amex,
    Visa,
    Discover,
    DinerClub,
    JCB};

@interface CreditCardObject : NSObject

@property(nonatomic, strong)NSString *cvc;
@property(nonatomic, strong)NSString *cardNumber;
@property(nonatomic, strong)NSString *last4;
@property(nonatomic, strong)NSString *expire;
@property(nonatomic, strong)NSString *postalCode;
@property(nonatomic, strong)AddressObject *billingAddress;
@property(nonatomic)enum CardType cardType;

@end
