Pod::Spec.new do |spec|
  s.name         = "TIC_Web_SaaS_SDK"
  s.version      = "1.0.0"
  s.summary      = "腾讯TIC Web SaaS SDK"
  s.description  = <<-DESC
                      腾讯云互动教育极简单接入SaaS的Web方案
                   DESC
  s.homepage     = "https://github.com/JamesChenGithub/TIC_Web_SaaS_SDK"
  s.license      = "MIT"
  s.license      = { :type => "MIT", :file => "LICENSE" }
  s.author             = "alexichen"
  s.platform     = :ios
  s.platform     = :ios, "9.0"

  s.source       = { :git => "https://github.com/JamesChenGithub/TIC_Web_SaaS_SDK.git", :tag => "#{s.version}" }

  # the framework upload to Cocoa Pods
  s.vendored_frameworks = 'TIC_Web_SaaS_SDK.framework'
  s.frameworks = 'Foundation'
  s.dependency 'Masonry'
  s.dependency 'YYModel'
  s.dependency 'TXLiteAVSDK_TRTC'
end
