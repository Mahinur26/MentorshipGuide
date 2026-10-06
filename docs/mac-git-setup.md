# Git/Github Guide

## What Git and GitHub actually are

**Git** is a program on your computer. It takes snapshots of your project so you
can see what changed, go back to an earlier version, and work on an idea without
breaking what already works.

**GitHub** is a website that stores copies of Git projects online. It's how your
code gets off your laptop so mentors can read it, comment on it, and help.

A useful comparison: Git is like the version history in Google Docs, except you
decide when each save point happens and you write a note explaining it. GitHub is
the part where the document lives in the cloud and other people can see it.

---

## Create your GitHub account

Go to **[github.com/signup](https://github.com/signup)** and make an account.

- **Use an email you'll keep.** Not a school email that gets deleted after you
  graduate.

---

## Installing Git on macOS

We'll install Git through **Homebrew**. Homebrew is a package manager - a tool
that installs and updates other developer tools for you. It's worth setting up now since you'll likely use it again later in your career. It keeps everything in one
place instead of scattered downloads.

Everything below happens in **Terminal**. Open it with `Cmd + Space`, type
`Terminal`, and press Enter.

### 1. Install Homebrew

Paste this in and press Enter:

```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

A few things to expect:

- It asks for your **Mac login password**. Typing it shows nothing on screen —
  no dots, no asterisks. That's normal. Type it and press Enter.
- It may ask you to press Enter once to confirm.
- It takes several minutes to download and prints a lot of text. Let it run.

### 2. Add Homebrew to your PATH

This allows you to use the `brew` command in your terminal.
Run these two lines in the terminal:

```bash
echo 'eval "$(/opt/homebrew/bin/brew shellenv)"' >> ~/.zprofile
eval "$(/opt/homebrew/bin/brew shellenv)"
```

Confirm it worked:

```bash
brew --version
```

You should see something like `Homebrew 6.0.22`. If you get
`command not found: brew`, quit Terminal entirely, reopen it, and try again.

### 3. Install Git

```bash
brew install git
```

Then confirm:

```bash
git --version
```

A version number means you're done. Move on to
[First-time setup](#first-time-setup).

<details>
<summary>Already have Git? Or want to skip Homebrew?</summary>

macOS can supply a version of Git on its own, through Apple's command line
developer tools. Run `git --version` — if you get a version number, you already
have it and it will work fine, but will likely need to be updated.

If you get a popup offering to install the developer tools, you can click
**Install** and use that instead of Homebrew.

I still recommend Homebrew. Apple's Git tends to lag a few versions behind, and
you'll want Homebrew for other tools anyways.

</details>

---

## First-time setup

Git stamps your name and email onto every snapshot you make, so it knows who did
what. You will have to only set these up once.

In Terminal (macOS) or Git Bash (Windows), run both lines — substituting your own
name and the email you used for GitHub:

```bash
git config --global user.name "Your Name"
git config --global user.email "you@example.com"
```

Then set the default branch name to `main`, which is what GitHub uses:

```bash
git config --global init.defaultBranch main
```

Check that it took:

```bash
git config --global --list
```

You should see your name and email in the output.

> **Use the same email as your GitHub account.** If they don't match, your
> commits won't be linked to your profile on GitHub — they'll show up as
> belonging to nobody.

---

## The words you'll keep hearing

You don't need to memorize these. Come back when a word stops making sense.

| Word | What it means |
|---|---|
| **Repository** (repo) | A project folder that Git is tracking. This project lives in one. |
| **Clone** | Download a copy of a repo from GitHub onto your computer. |
| **Commit** | One saved snapshot, with a note explaining what changed. |
| **Branch** | A parallel line of work. Lets you try something without touching the working version. Basically like another save file/version. |
| **`main`** | The primary branch that should contain working code |
| **Remote** | The copy of the repo that lives on GitHub. Usually nicknamed `origin`. |
| **Push** | Send your commits up to GitHub. |
| **Pull** | Bring down commits other people pushed. |
| **Pull request** (PR) | A request to merge your branch into `main`, so others can review it first. |
| **Merge** | Combine one branch's changes into another. |

---

## Cheat sheet

Print this, or keep the tab open.

```bash
# Starting work
git checkout main            # switch to the main branch
git pull                     # get the latest changes
git checkout -b my-branch    # create a branch and switch to it

# While working
git status                   # what's changed? what branch am I on?
git diff                     # show me exactly what I changed
git add .                    # stage all changes
git commit -m "message"      # save a snapshot

# Sharing work
git push -u origin my-branch # first push of a new branch
git push                     # every push after that

# Looking around
git log --oneline            # list recent commits
git branch                   # list branches, marking the current one
git checkout main            # switch back to main
```

---

[← Back to the main guide](../README.md)
