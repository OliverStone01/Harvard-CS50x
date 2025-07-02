/* Starting Data */
-- Date = 28/July/2024
-- Street = Humphrey Street


/* Crime Sceen Report */
-- The first thing I did was check the Crime Sceen Report database for any reports made
-- on the day of the crime.

SELECT id, description
FROM crime_scene_reports
WHERE year = '2024'
AND month = '7'             -- July is the 7th month.
AND day = '28'
AND street = 'Humphrey Street';

-- This returned 2 reports. The first is about the missing Duck and another about littering.
-- Here is the id and description of the Duck report.

-- id = 295
-- Description:
-- Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery.
-- Interviews were conducted today with three witnesses who were present at the time -
-- each of their interview transcripts mentions the bakery.

-- I've taken the relevent information from the report and added it to the Data Tracker:
-- Time = 10:15am
-- Location = Humphrey Street Bakery
-- Crime Sceen Report ID = 295
-- Witnesses = 3 (All present at the time of the crime & all mention the Bakery)


/* Interview Reports */
-- The next thing I did was check the interviews on the same date and look for ones that mentioned the bakery.
SELECT id, name, transcript
FROM interviews
WHERE year = '2024'
AND month = '7'
AND day = '28';

-- Here are the interviews I found that mentioned the Bakery.

-- ID: 161
-- Name: Ruth
-- Transcript:
-- Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away.
-- If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.

-- Key Information:
-- 10 Minutes after the theft (10:15 to 10:25) the thied got in a car from the bakery parking lot.


-- ID: 162
-- Name: Eugene
-- Transcript:
-- I don't know the thief's name, but it was someone I recognized.
-- Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.

-- Key Information:
-- Eugene recognized the thief and saw the thief earlier in the morning (Before 10:15) at an ATM on Leggett Street withdrawing money.


-- ID: 163
-- Name: Raymond
-- Transcript:
-- As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say
-- that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the
-- phone to purchase the flight ticket.

-- Key Information:
-- when the thief left the bakery, they made a phone call for less than a minuet planning.


/* Bakery Security Logs */

-- During Ruths Interview (Interview ID: 161). They mentioned that 10 minutes after the theft, they saw the thief get in a car
-- from the parking lot. I will now check the Bakery security logs to see which cars got picked leaving after 10:15 and before 10:30
-- ordered by id to get the latest input during those times.

SELECT bakery_security_logs.id, hour, minute, people.license_plate, name, phone_number, passport_number
FROM bakery_security_logs
JOIN people
ON bakery_security_logs.license_plate = people.license_plate
WHERE year = '2024'
AND month = '7'
AND day = '28'
AND hour = '10'
AND minute > 15
AND minute < 30
ORDER BY bakery_security_logs.id
DESC;

-- Here are the 8 plates that I got back:
-- +-----+------+--------+---------------+---------+----------------+-----------------+
-- | id  | hour | minute | license_plate |  name   |  phone_number  | passport_number |
-- +-----+------+--------+---------------+---------+----------------+-----------------+
-- | 267 | 10   | 23     | 0NTHK55       | Kelsey  | (499) 555-9472 | 8294398571      |
-- | 266 | 10   | 23     | 322W7JE       | Diana   | (770) 555-1861 | 3592750733      |
-- | 265 | 10   | 21     | L93JTIZ       | Iman    | (829) 555-5269 | 7049073643      |
-- | 264 | 10   | 20     | G412CB7       | Sofia   | (130) 555-0289 | 1695452385      |
-- | 263 | 10   | 19     | 4328GD8       | Luca    | (389) 555-5198 | 8496433585      |
-- | 262 | 10   | 18     | 6P58WS2       | Barry   | (301) 555-4174 | 7526138472      |
-- | 261 | 10   | 18     | 94KL13X       | Bruce   | (367) 555-5533 | 5773159633      |
-- | 260 | 10   | 16     | 5P2BI95       | Vanessa | (725) 555-4692 | 2963008352      |
-- +-----+------+--------+---------------+---------+----------------+-----------------+

/* ATM Transactions */

-- During Eugenes interview (Interview ID: 162), they mentioned that they saw the thief at the ATM earlier the same morning
-- on Leggett Street withdrawing money. My plan is to now look at all transactions and bank account info from that morning (Before 10:15am) and see who
-- withdrew money from that location on that day.

SELECT name, phone_number, passport_number
FROM atm_transactions
JOIN bank_accounts
ON atm_transactions.account_number = bank_accounts.account_number
JOIN people
ON bank_accounts.person_id = people.id
WHERE year = '2024'
AND month = '7'
AND day = '28'
AND atm_location = 'Leggett Street'
AND transaction_type = 'withdraw';

-- Here is a list of all the returned data:
-- +---------+----------------+-----------------+
-- |  name   |  phone_number  | passport_number |
-- +---------+----------------+-----------------+
-- | Bruce   | (367) 555-5533 | 5773159633      |
-- | Diana   | (770) 555-1861 | 3592750733      |
-- | Brooke  | (122) 555-4581 | 4408372428      |
-- | Kenny   | (826) 555-1652 | 9878712108      |
-- | Iman    | (829) 555-5269 | 7049073643      |
-- | Luca    | (389) 555-5198 | 8496433585      |
-- | Taylor  | (286) 555-6063 | 1988161715      |
-- | Benista | (338) 555-6650 | 9586786673      |
-- +---------+----------------+-----------------+

/* Phone Calls */

-- During Raymonds interview (interview id: 163) they mentioned they saw the thief take a less that one minute phone call when leaving the sceen.
-- I will call to the database to get the numbers used during that day that lasted less that a minute.

SELECT *
FROM phone_calls
WHERE year = '2024'
AND month = '7'
AND day = '28'
AND duration < 60;

-- Here are all the results:

-- +-----+----------------+----------------+------+-------+-----+----------+
-- | id  |     caller     |    receiver    | year | month | day | duration |
-- +-----+----------------+----------------+------+-------+-----+----------+
-- | 221 | (130) 555-0289 | (996) 555-8899 | 2024 | 7     | 28  | 51       |
-- | 224 | (499) 555-9472 | (892) 555-8872 | 2024 | 7     | 28  | 36       |
-- | 233 | (367) 555-5533 | (375) 555-8161 | 2024 | 7     | 28  | 45       |
-- | 251 | (499) 555-9472 | (717) 555-1342 | 2024 | 7     | 28  | 50       |
-- | 254 | (286) 555-6063 | (676) 555-6554 | 2024 | 7     | 28  | 43       |
-- | 255 | (770) 555-1861 | (725) 555-3243 | 2024 | 7     | 28  | 49       |
-- | 261 | (031) 555-6622 | (910) 555-3251 | 2024 | 7     | 28  | 38       |
-- | 279 | (826) 555-1652 | (066) 555-9701 | 2024 | 7     | 28  | 55       |
-- | 281 | (338) 555-6650 | (704) 555-2131 | 2024 | 7     | 28  | 54       |
-- +-----+----------------+----------------+------+-------+-----+----------+


/* Thief reveal */

-- Based on the following information, the thief is Bruce.

-- Reason:
-- Bruce was the only one that withdrew money at the ATM and who's car left the Bakery within 10 minutes of the crime.


/* Accomplice Reveal */

-- Based on the following information, the accomplice is Robin.

-- Reason:
-- As Bruce is the thief, they made a phone call to Robin on phone_call id 233.

SELECT name
FROM people
WHERE phone_number
IN
(
    SELECT receiver
    FROM phone_calls
    WHERE id = '233'
);

-- This returned:
-- +-------+
-- | name  |
-- +-------+
-- | Robin |
-- +-------+


/* Location fled to */

-- location = New York City

-- What i'm going to do next is take Bruces passport number to search the passanger database to get the flight_id
-- then take that ID and get the destination airport under that flight_id. Then collect the city name from the airport
-- that has that id number.

SELECT city
FROM airports
WHERE id =
(
    SELECT destination_airport_id
    FROM flights
    WHERE id =
    (
        SELECT flight_id
        FROM passengers
        WHERE passport_number =
        (
            SELECT passport_number
            FROM people
            WHERE name = 'Bruce'
        )
    )
);
