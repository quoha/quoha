Some Notes
----------

Set up remote
-------------
```
$ git remote -v
YourGitHubAccountNameHere	https://github.com/YourGitHubAccountNameHere/quoha.git (fetch)
YourGitHubAccountNameHere	https://github.com/YourGitHubAccountNameHere/quoha.git (push)
origin	https://github.com/quoha/quoha.git (fetch)
origin	https://github.com/quoha/quoha.git (push)
```

Hub helps
---------

The hub tool has a super-easy interface for creating pull requests. The folks
working on the [Hugo](https://discuss.gohugo.io/t/hugo-development-how-to-contribute-code/2374)
project use it:

```
# install [hub](https://hub.github.com/) with alias to git
# clone the repository
$ go get -u -v github.com/quoha/quoha
$ cd $GOPATH/src/github.com/quoha/quoha/
# create branch to work against
$ git checkout -b issue/000006
# Create a unit test that fails and confirm it
$ go test ./...
# write the code
# confirm unit test passess
$ go test ./...
# always format the code before committing
$ gofmt
# add a nice commit [message](http://tbaggery.com/2008/04/19/a-note-about-git-commit-messages.html)
$ git commit
# then use hub to fork and push the changes
$ git fork
$ git push YourGitHubAccountNameHere issue/000006
$ git pull-request
```

Other references
----------------

Try "[Contributing to Open Source Git Repositories in Go](https://splice.com/blog/contributing-open-source-git-repositories-go/)
for an explanation.
