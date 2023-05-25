# CS2023 - Lab07
# Using OOP to design a "simple" adventure game

_author_ = "Thavishka Gamage"
_credits_ = "Worked independently"
_email_ = "gamagetd@mail.uc.edu" # Your email address

class Player(object):
    def __init__(self, name, place):
        """Create a player object."""
        self.name = name
        self.place = place
        self.backpack = []

    def look(self):
        self.place.look()

#RQ2
    def go_to(self, direction):
        """Go to direction if it's among the exits of player's current place.
        >>> swift= Place('Swift Hall', 'You are at Swift Hall', [], [])
        >>> bcc = Place('Bearcat Cafe', 'You are at Bearcat Cafe', [], [])
        >>> swift.add_exits([bcc])
        >>> bcc.add_exits([swift])
        >>> me = Player('player', swift)
        >>> me.go_to('Bearcat Cafe')
        You are at Bearcat Cafe
        >>> me.place.name
        'Bearcat Cafe'
        >>> me.go_to('Bearcat Cafe')
        Can't go to Bearcat Cafe from Bearcat Cafe.
        Try looking around to see where to go.
        >>> me.go_to('Swift Hall')
        You are at Swift Hall
        """
        self.place = self.place.exit_to(direction)
#RQ3
    def talk_to(self, person):
        """Talk to person if person is at player's current place.
        >>> robert = Character('Robert', 'Have to run for lecture!')
        >>> sather_gate = Place('Sather Gate', 'You are at Sather Gate', [robert], [])
        >>> me = Player('player', sather_gate)
        >>> me.talk_to(robert)
        Person has to be a string.
        >>> me.talk_to('Robert')
        Robert says: Have to run for lecture!
        >>> me.talk_to('Albert')
        Albert is not here.
        """
        if type(person) != str:
            print('Person has to be a string.')
        elif person in self.place.characters:
            print(person + " says: " + self.place.characters[person].talk())
        else:
            print(person + " is not here.")

#RQ4
    def take(self, thing):
        """Take a thing if thing is at player's current place
        >>> hotdog = Thing('Hotdog', 'A hot looking hotdog')
        >>> bcc = Place('BCC', 'You are at Bearcat Cafe', [], [hotdog])
        >>> me = Player('Player', bcc)
        >>> me.backpack
        []
        >>> me.take(hotdog)
        Thing should be a string.
        >>> me.take('dog')
        dog is not here.
        >>> me.take('Hotdog')
        Player takes the Hotdog
        >>> me.take('Hotdog')
        Hotdog is not here.
        >>> type(me.backpack[0])
        <class 'Thing'>
        """
        if type(thing) != str:
            print('Thing should be a string.')
        elif thing in self.place.things:
            self.backpack.append(self.place.take(thing))
            print(self.name + " takes the " + thing)
        else:
            print(thing + " is not here.")

    def check_backpack(self):
        """Print each item with its description and return a list of item names.
        >>> cookie = Thing('Cookie', 'A huge cookie')
        >>> donut = Thing('Donut', 'A huge donut')
        >>> cupcake = Thing('Cupcake', 'A huge cupcake')
        >>> bcc = Place('BCC', 'You are at Bearcat Cafe', [], [cookie, donut, cupcake])
        >>> me = Player('Player', bcc)
        >>> me.check_backpack()
        In your backpack:
            there is nothing.
        []
        >>> me.take('Cookie')
        Player takes the Cookie
        >>> me.check_backpack()
        In your backpack:
            Cookie - A huge cookie
        ['Cookie']
        >>> me.take('Donut')
        Player takes the Donut
        >>> food = me.check_backpack()
        In your backpack:
            Cookie - A huge cookie
            Donut - A huge donut
        >>> food
        ['Cookie', 'Donut']
        """
        print('In your backpack:')
        if not self.backpack:
            print('    there is nothing.')
        else:
            for item in self.backpack:
                print('   ', item.name, '-', item.description)
        return [item.name for item in self.backpack]


class Character(object):
    def __init__(self, name, message):
        self.name = name
        self.message = message

    def talk(self):
        return self.message


class Thing(object):
    def __init__(self, name, description):
        self.name = name
        self.description = description


class Place(object):
    def __init__(self, name, description, characters, things):
        self.name = name
        self.description = description
        self.characters = {character.name: character for character in characters}
        self.things = {thing.name: thing for thing in things}
        self.exits = {} # {'name': (exit, 'description')}

    def look(self):
        print('You are currently at ' + self.name + '. You take a look around and see:')
        print('Characters:')
        if not self.characters:
            print('    no one in particular')
        else:
            for character in self.characters:
                print('   ', character)
        print('Things:')
        if not self.things:
            print('    nothing in particular')
        else:
            for thing in self.things.values():
                print('   ', thing.name, '-', thing.description)
        self.check_exits()

    def exit_to(self, exit):
        if type(exit) != str:
            print('Exit has to be a string.')
            return self
        elif exit in self.exits:
            print(self.exits[exit][1])
            return self.exits[exit][0]
        else:
            print("Can't go to {} from {}.".format(exit, self.name))
            print("Try looking around to see where to go.")
            return self

    def take(self, thing):
        obj = self.things[thing]
        del self.things[thing]
        return obj

    def check_exits(self):
        print('You can exit to:')
        for exit in self.exits:
            print('   ',exit)

    def add_exits(self, places):
        for place in places:
            self.exits[place.name] = (place, place.description)


# Characters:
randy = Character('Randy', "I can't believe I lost my wallet again! "
                             "I wish someone could find it for me.")
albert = Character('Albert', 'Randy went to DAAP for potluck. You can find her there.')
yulin = Character('Yulin', 'Are you going to potluck? '
                           'You should bring some board games!')
jeffrey = Character('Jeffrey', 'No one brought food to the potluck! '
                               'Maybe the Bearcat Cafe (bcc) is open; we can get food there.')
derrick = Character('Derrick', 'I heard you like board games. '
                               'Have you gone to Gamestop?')
ken = Character('Ken', 'Hey! Want to play ultimate frisbee?')
student = Character('Student', 'I once went into TUC and got lost for 3 days! '
                               'That place is a maze!')


# Things:
wallet = Thing('Wallet', "Looks like Randy's wallet. We should return it to her.")
hotdog = Thing('Hotdog', 'Yummy! Bring it to potluck!')
cards = Thing('Monopoly', 'Just right for potluck!')

# Places:
tuc = Place('Tangeman University Center', 'You are at Tangeman University Center', [], [])
ccm = Place('CCM', 'You are at CCM', [], [wallet])
erc = Place('ERC', 'You are at ERC', [albert], [])
daap = Place('DAAP', 'You are at DAAP', [randy, jeffrey], [])
bcc = Place('Bearcat Cafe', 'You are at Bearcat Cafe', [], [hotdog])
baldwin = Place('Baldwin', 'You are in Baldwin', [yulin], [])
game_store = Place('Gamestop', 'You are at Gamestop', [], [cards])
starbucks = Place('Starbucks', 'You are at Starbucks', [], [])
swift = Place('Swift', 'You are at Swift', [], [])
rhodes = Place('Rhodes Hall', 'You are at Rhodes Hall', [derrick], [])
steger = Place('Steger Center', 'You are at Steger Center', [student], [])
nippert = Place('Nippert Stadium', 'You are at Nippert Stadium', [ken], [])


# Exits:
tuc.add_exits([bcc, rhodes, steger, nippert])
bcc.add_exits([tuc])
rhodes.add_exits([tuc, baldwin])
steger.add_exits([tuc, erc])
nippert.add_exits([tuc, ccm, baldwin, daap])
baldwin.add_exits([nippert, rhodes])
erc.add_exits([ccm, daap, swift, steger])
swift.add_exits([erc, game_store])
ccm.add_exits([erc, nippert])
daap.add_exits([starbucks, erc, nippert])
starbucks.add_exits([daap])
game_store.add_exits([nippert])

# RQ1: Game Player:
# The Player should start at tuc.
me = Player("Thavishka Gamage", tuc)


############################################
#   Game Configuration and REPL            #
############################################
try:
    import readline
except ImportError:
    pass

###########
# Parsing #
###########

def adv_parse(line):
    tokens = line.split()
    if not tokens:
        raise SyntaxError('No command given')
    command = tokens.pop(0)
    if command in ('talk', 'go'):
        if not tokens or tokens[0] != 'to':
            raise SyntaxError('Did you mean "{}"?'.format(COMMAND_FORMATS[command]))
        return (command + '_to', ' '.join(tokens[1:]))
    elif command == 'check':
        if not tokens or tokens[0] != 'backpack':
            raise SyntaxError('Did you mean "{}"?'.format(COMMAND_FORMATS['check backpack']))
        return ('check_backpack', '')
    else:
        return (command, ' '.join(tokens))

##############
# Evaluation #
##############

def adv_eval(exp):
    operator, operand = exp[0], exp[1]
    if operator not in COMMAND_NUM_ARGS:
        help()
        raise SyntaxError('Invalid command: {}'.format(operator))
    elif operator in SPECIAL_FORMS:
        function = SPECIAL_FORMS[operator]
    else:
        function = getattr(me, operator)

    if COMMAND_NUM_ARGS[operator] == 0:
        function()
    else:
        function(operand)

def help():
    print('There are {} possible commands:'.format(len(COMMAND_FORMATS)))
    for usage in COMMAND_FORMATS.values():
        print('   ', usage)

def check_win_state(player):
    """Checks if the player is in a winning state."""
    if player.place != starbucks:
        return False

    print()
    if len(player.check_backpack()) != 3:
        print()
        print("Looks like you're missing some items. Can't go to the potluck yet!")
        return False
    return True

########
# REPL #
########

def read_eval_print_loop():
    print(WELCOME_MESSAGE)
    if not isinstance(me, Player):
        print('Oh no! You need to create a player in lab07.py to start the game.')
        return

    help()
    while True:
        if check_win_state(me):
            print(WIN_MESSAGE)
            return
        print()
        try:
            line = input('adventure> ')
            exp = adv_parse(line)
            adv_eval(exp)
        except (KeyboardInterrupt, EOFError, SystemExit): # If you ctrl-c or ctrl-d
            print('\nGood game. Bye!')
            return
        # If the player input was badly formed or if something doesn't exist
        except SyntaxError as e:
            print('ERROR:', e)

#################
# Configuration #
#################

COMMAND_FORMATS = {
    'look': 'look',
    'go': 'go to [direction]',
    'take': 'take [thing]',
    'talk': 'talk to [character]',
    'check backpack': 'check backpack',
    'help': 'help',
}

COMMAND_NUM_ARGS = {
    'look': 0,
    'go_to': 1,
    'take': 1,
    'talk_to': 1,
    'check_backpack': 0,
    'help': 0,
}

SPECIAL_FORMS = {
    'help': help,
}

WELCOME_MESSAGE = """
Welcome to the adventure game!

It's a bright sunny day.
You are a cute little squirrel named {},
wandering around UC campus looking for food.

Let's go to ccm (CCM Cafe)
and see what we can find there!
""".format(me.name if isinstance(me, Player) else '______')

WIN_MESSAGE = """
You arrived just in time for the potluck!

Randy thanks you for finding her wallet.
Jeffrey devours the hot dog you brought.
Everyone gathers around for a long game of Monopoly.

Congratulations! You won the adventure game!
"""


if __name__ == '__main__':
    read_eval_print_loop()